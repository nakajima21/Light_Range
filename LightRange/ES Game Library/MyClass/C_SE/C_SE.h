#pragma once

//------------------------------------------------------------------------------
//	インクルードファイル
//------------------------------------------------------------------------------
#include "../../ESGLib.h"
#include <vector>

//------------------------------------------------------------------------------
//	SEManagerクラス定義
//------------------------------------------------------------------------------

class C_SE {
public:
	virtual ~C_SE(){};

	// シングルトンインスタンスの取得
	static C_SE& GetInstance()
	{ 
		static C_SE theSEManager;
		return theSEManager;
	}

	bool Initialize();

	int LoadSE(TCHAR* filename, const UINT multiple = 1);

	void PlaySE(int index);
	
	void LoadBGM(TCHAR* filename) { bgm = SoundDevice.CreateMusicFromFile(filename); };
	bool PlayBGM();

	int LoadLopeSE(TCHAR* filename);

	void PlayLopeSE(int _number);

	bool IsSeVolume(int _set_number);

	void StopLopeSE(int _number) { LopeSE[_number]->Stop(); };
	std::vector<SOUND> GetLopeSE() const { return LopeSE; };

	std::vector<SOUND> LopeSE;

	MUSIC GetBgm() { return bgm; };

private:
	C_SE() {};
	
	MUSIC bgm;

	// メンバ変数
	std::vector< std::vector<SOUND> > se;

	C_SE(const C_SE&) = delete;
	C_SE& operator=(const C_SE&) = delete;
	C_SE(C_SE&&) = delete;
	C_SE& operator=(C_SE&&) = delete;
};

//------------------------------------------------------------------------------
//	インライン関数定義
//------------------------------------------------------------------------------
inline C_SE& SNDMgr() { return C_SE::GetInstance(); }
#define SNDMANAGER C_SE::GetInstance()