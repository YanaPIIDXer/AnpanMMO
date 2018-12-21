/**
 * @file $FILE_NAME$
 * @brief $CLASS_COMMENT$
 * @author NativePacketGenerator
 */

#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
$INCLUDES$

/**
 * @brief $CLASS_COMMENT$
 */
class $CLASS_NAME$ $BASE_CLASS_NAME$
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	$GET_PACKET_ID_FUNCTION$

	$ENUMS$

	$MEMBERS$

	/**
	 * @brief コンストラクタ
	 */
	$CLASS_NAME$()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	$CONSTRUCTOR$


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		$SERIALIZE_MEMBERS$
		return true;
	}
};

#endif		// #ifndef $INCLUDE_GUARD$
