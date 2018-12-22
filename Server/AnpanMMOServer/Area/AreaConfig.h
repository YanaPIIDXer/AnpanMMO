/**
 * @file AreaConfig.h
 * @brief エリア設定クラス
 * @author YanaP
 */
#ifndef __AREACONFIG_H__
#define __AREACONFIG_H__

/**
 * @brief エリア設定
 */
class AreaConfig
{

public:

	//! 幅最小値.
	static const float MinWidth;

	//! 幅最大値.
	static const float MaxWidth;

	//! 高さ最小値.
	static const float MinHeight;

	//! 高さ最大値.
	static const float MaxHeight;

	//! 奥行き最小値.
	static const float MinDepth;

	//! 奥行き最大値.
	static const float MaxDepth;

};

#endif		// #ifndef __AREACONFIG_H__
