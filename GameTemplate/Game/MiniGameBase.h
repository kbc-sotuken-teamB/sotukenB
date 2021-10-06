#pragma once
#include <tuple>
/// <summary>
/// ミニゲームの基底クラスです。
/// スコアステージで必要なパラメータを送る関数と、
/// 何かしら基底クラスに必要なものがあれば追加していきます。要望とかはディスコ、Line、直接等々連絡くだしあ
/// </summary>
class MiniGameBase : public IGameObject
{
public:
	MiniGameBase() {};
	virtual ~MiniGameBase() {/*スコアステージのメモリ確保*/ };
	std::tuple<int,int,int,int>GetScore() {
		return std::forward_as_tuple(m_score[0], m_score[1], m_score[2], m_score[3]);
	}
	/// <summary>
	/// 勝者のプレイヤー番号を入れてください
	/// </summary>
	/// <param name="winner"></param>
	void SetWinner(int winner) {
		m_winner = winner;
	}
	/// <summary>
	/// スコアをプレイヤー１から順番に入れてください。
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
	int m_winner = 0;   //勝者の番号を入れるヤツ。
	int m_score[4] = {};//スコアです。これ使ってくださいお願いします。配列にすんなカスと言えば変数4つ作ります

private:
	
};

