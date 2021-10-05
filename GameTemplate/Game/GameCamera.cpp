#include "stdafx.h"
#include "GameCamera.h"

GameCamera::GameCamera()
{
}

GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	m_position = { 0.0f,200.0f,-200.0f }; //�������_�̐ݒ�
	m_target = Vector3::Zero;			  //���������_�̐ݒ�
	g_camera3D->SetPosition(m_position); //���W�̏�����
	g_camera3D->SetTarget(m_target);	 //�����_�̏�����
	g_camera3D->SetFar(10000.0f);		 //�����ʂ̏�����
	g_camera3D->SetNear(1.0f);			 //�ߕ��ʂ̏�����

	return true;
}

void GameCamera::Update()
{
	g_camera3D->SetPosition(m_position); //���W�̍X�V
	g_camera3D->SetTarget(m_target);	 //�����_�̍X�V
	g_camera3D->SetFar(10000.0f);		 //�����ʂ̍X�V
	g_camera3D->SetNear(1.0f);			 //�ߕ��ʂ̍X�V
}

void GameCamera::MathMove()
{
	
}

void GameCamera::SwitchPlayerMove()
{
}

void GameCamera::FreeMove(int playerNum)
{
	playerNum = 0;//�������f�o�b�N���邽�߂ɂƂ肠��������Ă���l�ł��B��ň����ʂ�ɓ����悤�ύX���܂�

	if (playerNum < 0 || playerNum > 3) {		
		std::abort();							//�������s���̂Ƃ���O�����܂�
	}

	float x = g_pad[playerNum]->GetLStickXF();	//�p�b�h��LStickX�̒l���擾
	float z = g_pad[playerNum]->GetLStickYF();	//�p�b�h��LStickY�̒l���擾
	float moveSpeed = 20.0f;
	if (fabsf(x < 0.01)) {						//X�����ɃX�e�B�b�N���X���Ă�����
		m_position.x += x * moveSpeed;			//X�����ɓ��͗ʁ~�X�s�[�h�����_�ƒ����_�ɉ��Z
		m_target.x += x * moveSpeed;
	}
	if (fabsf(z < 0.01)) {						//Y�����ɃX�e�B�b�N���X���Ă�����
		m_position.z += z * moveSpeed;			//Z�����ɓ��͗ʁ~�X�s�[�h�����_�ƒ����_�ɉ��Z
		m_target.z += z * moveSpeed;
	}
}