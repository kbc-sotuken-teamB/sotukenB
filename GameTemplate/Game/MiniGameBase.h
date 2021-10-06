#pragma once
#include <tuple>
/// <summary>
/// �~�j�Q�[���̊��N���X�ł��B
/// �X�R�A�X�e�[�W�ŕK�v�ȃp�����[�^�𑗂�֐��ƁA
/// ����������N���X�ɕK�v�Ȃ��̂�����Βǉ����Ă����܂��B�v�]�Ƃ��̓f�B�X�R�ALine�A���ړ��X�A����������
/// </summary>
class MiniGameBase : public IGameObject
{
public:
	MiniGameBase() {};
	virtual ~MiniGameBase() {/*�X�R�A�X�e�[�W�̃������m��*/ };
	std::tuple<int,int,int,int>GetScore() {
		return std::forward_as_tuple(m_score[0], m_score[1], m_score[2], m_score[3]);
	}
	/// <summary>
	/// ���҂̃v���C���[�ԍ������Ă�������
	/// </summary>
	/// <param name="winner"></param>
	void SetWinner(int winner) {
		m_winner = winner;
	}
	/// <summary>
	/// �X�R�A���v���C���[�P���珇�Ԃɓ���Ă��������B
	/// </summary>
	/// <param name="num0">player1Score</param>
	/// <param name="num1">player2Score</param>
	/// <param name="num2">player3Score</param>
	/// <param name="num3">player4Score</param>
	void SetScore(int num0,int num1,int num2,int num3) {
		m_score[0] = num0;
		m_score[1] = num1;
		m_score[2] = num2;
		m_score[3] = num3;
	};

protected:
	int m_winner = 0;   //���҂̔ԍ������郄�c�B
	int m_score[4] = {};//�X�R�A�ł��B����g���Ă����������肢���܂��B�z��ɂ���ȃJ�X�ƌ����Εϐ�4���܂�

private:
	
};

