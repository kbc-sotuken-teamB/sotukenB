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
	/// ターン中のプレイヤーの番号を渡してください。その番号のPadでカメラが動きます。
	/// </summary>
	/// <param name="playerNum">playerNum</param>
	void FreeMove(int playerNum);
	/// <summary>
	/// マス移動のときの動き。プレイヤーを追従するのみとなっております。
	/// </summary>
	void MathMove();
	/// <summary>
	/// ターンプレイヤーが切り替わる時に、滑らかに次のプレイヤーに追従するかもしれない関数です。
	/// </summary>
	void SwitchPlayerMove();
private:
	Vector3 m_position = Vector3::Zero;			//視点
	Vector3 m_target = Vector3::One;			//注視点
	Quaternion m_rot = Quaternion::Identity;	//回転率
	Player* Player[4] = {};				//プレイヤーのインスタンス
};

