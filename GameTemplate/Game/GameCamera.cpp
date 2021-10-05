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
	m_position = { 0.0f,200.0f,-200.0f }; //初期視点の設定
	m_target = Vector3::Zero;			  //初期注視点の設定
	g_camera3D->SetPosition(m_position); //座標の初期化
	g_camera3D->SetTarget(m_target);	 //注視点の初期化
	g_camera3D->SetFar(10000.0f);		 //遠平面の初期化
	g_camera3D->SetNear(1.0f);			 //近平面の初期化

	return true;
}

void GameCamera::Update()
{
	g_camera3D->SetPosition(m_position); //座標の更新
	g_camera3D->SetTarget(m_target);	 //注視点の更新
	g_camera3D->SetFar(10000.0f);		 //遠平面の更新
	g_camera3D->SetNear(1.0f);			 //近平面の更新
}

void GameCamera::MathMove()
{
	
}

void GameCamera::SwitchPlayerMove()
{
}

void GameCamera::FreeMove(int playerNum)
{
	playerNum = 0;//来栖がデバックするためにとりあえず入れてある値です。後で引数通りに動くよう変更します

	if (playerNum < 0 || playerNum > 3) {		
		std::abort();							//引数が不正のとき例外投げます
	}

	float x = g_pad[playerNum]->GetLStickXF();	//パッドのLStickXの値を取得
	float z = g_pad[playerNum]->GetLStickYF();	//パッドのLStickYの値を取得
	float moveSpeed = 20.0f;
	if (fabsf(x < 0.01)) {						//X方向にスティックが傾いていたら
		m_position.x += x * moveSpeed;			//X方向に入力量×スピードを視点と注視点に加算
		m_target.x += x * moveSpeed;
	}
	if (fabsf(z < 0.01)) {						//Y方向にスティックが傾いていたら
		m_position.z += z * moveSpeed;			//Z方向に入力量×スピードを視点と注視点に加算
		m_target.z += z * moveSpeed;
	}
}