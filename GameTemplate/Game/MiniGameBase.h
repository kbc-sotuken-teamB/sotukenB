#pragma once
/// <summary>
/// �~�j�Q�[���̊��N���X�ł��B
/// �X�R�A�X�e�[�W�ŕK�v�ȃp�����[�^�𑗂�֐��ƁA
/// ����������N���X�ɕK�v�Ȃ��̂�����Βǉ����Ă����܂��B�v�]�Ƃ��̓f�B�X�R�ALine�A���ړ��X�A����������
/// </summary>
class MiniGameBase : public IGameObject
{
public:
	MiniGameBase() {};
	virtual ~MiniGameBase() {};
	int GetScore();
protected:

	
};

