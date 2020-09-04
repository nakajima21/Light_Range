#include "C_SE.h"

bool C_SE::Initialize()
{
	se.clear();
	se.reserve(4);

	SoundDevice.ReleaseAllMusics();
	SoundDevice.ReleaseAllSounds();

	return true;
}

int C_SE::LoadSE(TCHAR* filename, const UINT multiple)
{
	std::vector<SOUND> se_vec;
	se_vec.assign(multiple, nullptr);

	SoundDevice.CreateSharedSoundFromFile(filename, &se_vec[0], multiple, false);
	se.push_back(se_vec);

	return se.size() - 1;
}

void C_SE::PlaySE(int index)
{
	if (se[index].size() <= 1) {
		se[index][0]->Play();
		return;
	}

	for (UINT i = 0; i < se[index].size(); i++) {
		if (!se[index][i]->IsPlaying()) {
			se[index][i]->Play();
			return;
		}
	}

	se[index][0]->Play();
}

bool C_SE::PlayBGM()
{
	if (bgm->IsPlaying())return FALSE;
	bgm->Play();
	return TRUE;
}

void C_SE::PlayLopeSE(int _number)
{
	if (!LopeSE[_number]->IsPlaying()) {
		LopeSE[_number]->Play();
	}
}

int C_SE::LoadLopeSE(TCHAR* filename)
{
	LopeSE.push_back(SoundDevice.CreateSoundFromFile(filename));

	return LopeSE.size() - 1;
}

bool C_SE::IsSeVolume(int _set_number)
{
	if (LopeSE[_set_number]->GetVolume() <= 0){ return true; } else return false;
}


