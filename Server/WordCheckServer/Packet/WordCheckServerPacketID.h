/**
 * @file $FILE_NAME$
 * @brief �p�P�b�g�h�c��`.
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKSERVERPACKETID_H__
#define __WORDCHECKSERVERPACKETID_H__

/**
 * @brief �p�P�b�g�h�c��`.
 */
class WordCheckPacketID
{

public:

	/**
	 * @enum EID
	 * �p�P�b�g�h�c
	 */
	enum EID
	{
		//! ���[�h�`�F�b�N�v���p�P�b�g
		WordCheckChatRequest = 0x80,
		//! ���[�h�`�F�b�N���ʃp�P�b�g
		WordCheckChatResult = 0x81,
		
	};
};

#endif		// #ifndef __WORDCHECKSERVERPACKETID_H__
