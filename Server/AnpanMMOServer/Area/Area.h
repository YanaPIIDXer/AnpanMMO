#ifndef __AREA_H__
#define __AREA_H__

struct AreaItem;

/**
 * �G���A�N���X
 */
class Area
{

public:

	// �R���X�g���N�^
	Area(const AreaItem *pInItem);

	// �f�X�g���N�^
	~Area() {}
	
private:

	// �}�X�^�f�[�^
	const AreaItem *pItem;

};

#endif		// #ifndef __AREA_H__
