#pragma once
/// <summary>
/// ミニゲームの基底クラスです。
/// スコアステージで必要なパラメータを送る関数と、
/// 何かしら基底クラスに必要なものがあれば追加していきます。要望とかはディスコ、Line、直接等々連絡くだしあ
/// </summary>
class MiniGameBase : public IGameObject
{
public:
	MiniGameBase() {};
	virtual ~MiniGameBase() {};
	int GetScore();
protected:

	
};

