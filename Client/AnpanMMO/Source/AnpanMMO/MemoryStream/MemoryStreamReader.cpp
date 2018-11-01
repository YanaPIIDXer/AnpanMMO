#include "MemoryStreamReader.h"
#include "EndianConverter.h"

//�R���X�g���N�^
MemoryStreamReader::MemoryStreamReader( const u8 *_pData , const int _Size )
	: Size( _Size ) ,
	  CurrentPosition( 0 ) ,
	  bError( false )
{

	pData = new u8[Size];
	memcpy( pData , _pData , Size );

}

//�����t���R�Q�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( s32 *pValue )
{

	s32 NetworkValue;

	if( !Read( &NetworkValue , sizeof( s32 ) ) )
	{

		return false;
		
	}

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//���������R�Q�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( u32 *pValue )
{

	u32 NetworkValue;

	if( !Read( &NetworkValue , sizeof( u32 ) ) )
	{

		return false;
		
	}

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//�����t���P�U�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( s16 *pValue )
{

	s16 NetworkValue;

	if( !Read( &NetworkValue , sizeof( s16 ) ) )
	{

		return false;
		
	}

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//���������P�U�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( u16 *pValue )
{

	u16 NetworkValue;

	if( !Read( &NetworkValue , sizeof( u16 ) ) )
	{

		return false;
		
	}

	*pValue = EndianConverter::Convert( NetworkValue );
	return true;

}

//�����t���W�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( s8 *pValue )
{

	return Read( pValue , sizeof( s8 ) );

}

//���������W�r�b�g�V���A���C�Y
bool MemoryStreamReader::Serialize( u8 *pValue )
{

	return Read( pValue , sizeof( u8 ) );

}

//������V���A���C�Y
bool MemoryStreamReader::Serialize( std::string *pValue )
{

	//������̒���
	s32 Length = 0;
	if( !Serialize( &Length ) )
	{

		return false;

	}

	//������{��
	char *pStr = new char[Length + 1];
	bool bResult = Read( pStr , Length );

	if( bResult )
	{

		pStr[Length] = '\0';
		*pValue = pStr;

	}

	delete []pStr;
	return bResult;

}

// float�V���A���C�Y
bool MemoryStreamReader::Serialize(float *pValue)
{

	float NetworkValue;
	if(!Read(&NetworkValue, sizeof(float)))
	{

		return false;

	}

	*pValue = EndianConverter::Convert(NetworkValue);
	return true;

}

//�w�肵���T�C�Y���̓ǂݍ���
bool MemoryStreamReader::Read( void *pValue , int ReadSize )
{

	if( ReadSize + CurrentPosition > Size )
	{

		//�f�[�^�T�C�Y�I�[�o�[
		bError = true;
		return false;

	}

	memcpy( pValue , ( pData + CurrentPosition ) , ReadSize );

	CurrentPosition += ReadSize;
	return true;

}
