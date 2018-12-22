/**
 * @file HeightMap.h
 * @brief ハイトマップクラス
 * @author YanaP
 */
#ifndef __HEIGHTMAP_H__
#define __HEIGHTMAP_H__

#include "Bitmap.h"

class Vector3D;

/**
 * @class HeightMap
 * @brief ハイトマップ
 */
class HeightMap
{

public:

	/**
	 * @brief コンストラクタ
	 */
	HeightMap();

	/**
	 * @brief デストラクタ
	 */
	~HeightMap() {}

	/**
	 * @fn bool Load(const std::string &FilePath)
	 * @brief 読み込み
	 * @param[in] FilePath ファイルパス
	 * @return 成功したらtrueを返す
	 */
	bool Load(const std::string &FilePath);

	/**
	 * @fn float GetHeight(float X, float Z) const
	 * @brief 高さを取得
	 * @param[in] X Ｘ座標
	 * @param[in] Z Ｚ座標
	 * @return 高さ
	 */
	float GetHeight(float X, float Z) const;

	/**
	 * @fn bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
	 * @brief 移動できるかどうかをチェック
	 * @details レイキャストによるチェック
	 * @param[in] Start チェック開始地点
	 * @param[in] End チェック終了地点
	 * @param[in] float ClimbableHeight 登ることができる高さ
	 * @param[out] OutHit レイが当たった地点
	 * @return 移動可能ならtrueを返す
	 */
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

private:

	// レイ分割数.
	static const int RayDivisionCount;

	// ビットマップデータ
	Bitmap Bmp;

};

#endif		// #ifndef __HEIGHTMAP_H__
