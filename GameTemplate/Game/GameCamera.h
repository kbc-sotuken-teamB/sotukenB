#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	/// <summary>
	/// �^�[�����̃v���C���[�̔ԍ���n���Ă��������B���̔ԍ���Pad�ŃJ�����������܂��B
	/// </summary>
	/// <param name="playerNum">playerNum</param>
	void FreeMove(int playerNum);
	/// <summary>
	/// �}�X�ړ��̂Ƃ��̓����B�v���C���[��Ǐ]����݂̂ƂȂ��Ă���܂��B
	/// </summary>
	void MathMove();
	/// <summary>
	/// �^�[���v���C���[���؂�ւ�鎞�ɁA���炩�Ɏ��̃v���C���[�ɒǏ]���邩������Ȃ��֐��ł��B
	/// </summary>
	void SwitchPlayerMove();
private:
	Vector3 m_position = Vector3::Zero;			//���_
	Vector3 m_target = Vector3::One;			//�����_
	Quaternion m_rot = Quaternion::Identity;	//��]��
	Player* Player[4] = {};				//�v���C���[�̃C���X�^���X
};

