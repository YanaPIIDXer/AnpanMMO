// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#define _WIN32_WINNT 0x0501

#include <stdio.h>

#include <boost/asio.hpp>
#include "basic_repeating_timer.h"

using namespace boost;
using asio::ip::tcp;

#include "TypeDefs.h"

// �X�N���v�g���W���[�����N���C�A���g�Ƃ̌݊����������߂̂��܂��Ȃ�
#define SCRIPTMODULE_API

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă�������

#endif		// #ifndef __STDAFX_H__
