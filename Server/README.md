# boost���C�u����
�T�[�o�v���O�����ł�boost���C�u�������g�p���Ă��܂��B  
�o�[�W������**1.68**�ł��B  
���炩����boost���C�u�������C���X�g�[�����Ă����A�ȉ��̂悤�Ƀp�X��ʂ��Ă����Ă��������B  
**BOOST_INCLUDE:{BoostDir}\include\boost-1_68**  
**BOOST_LIB:{BoostDir}\lib**  

# MySQL�R�l�N�^
�ȉ���URL����**32Bit�ł�**�_�E�����[�h���Ă��������B  
http://download.nust.na/pub6/mysql/downloads/connector/c/index.html  
�_�E�����[�h�������̂�W�J���A�ȉ��̒ʂ�p�X��ʂ��Ă��������B  
**MYSQL_C_INCLUDE:{ConnectorRoot}\include**  
**MYSQL_C_LIB:{ConnectorRoot}\lib**

# Lua
�ȉ���URL����**32Bit�ł�**�_�E�����[�h���Ă��������B
https://sourceforge.net/projects/luabinaries/files/5.3.4/Windows%20Libraries/Static/  
�_�E�����[�h�������̂�W�J���A�ȉ��̒ʂ�p�X��ʂ��Ă��������B  
**LUA_INCLUDE:{LuaRoot}/include**  
**LUA_LIB:{LuaRoot}**

# Linux�T�[�o�ɂ���
�T�[�o�v���O�������f�v���C����Linux�T�[�o�́A�p�ӂł����}�V���̃X�y�b�N�����炸�A�ȉ��̂悤�ȃX�y�b�N�ƂȂ��Ă���܂��B  
**OS : Fedora Core 5**  
**gcc : gcc4.1.1**  
gcc�̃o�[�W�������Â��ׁAC++11���g���Ȃ��_�ɒ��ӂ��Ă��������B  

# �N������
�T�[�o�̋N���ɂ͈ȉ��̏������K�v�ł��B  
1.MySQL��**AnpanMMO**�f�[�^�x�[�X��p�ӂ���B�i�g�p���郆�[�U�Ɍ������^���Ă������B�j  
2.Server�f�B���N�g���Ɉړ����A**mysql -u {���[�U��} -p{�p�X���[�h} -D AnpanMMO < AnpanMMO.sql**�R�}���h�����s���A�e�[�u����W�J���Ă����B  
3.CacheServer�f�B���N�g���Ɉړ����A**DBUserData.txt**���쐬���A��s�ڂ�MySQL�Ń��O�C�����郆�[�U�����A��s�ڂɃp�X���[�h���L�q����B
3.���l��**AnpanMMOMaster**�f�[�^�x�[�X��p�ӂ��A�g�p���郆�[�U�Ɍ�����^���Ă����B
4.AnpanMMOServer�f�B���N�g������**MasterDBUserData.txt**���쐬���A��s�ڂ�AnpanMMOMaster�f�[�^�x�[�X���Q�Ƃ��郆�[�U�����A��s�ڂɃp�X���[�h���L�q����B  
5.4�̍�ƂƓ��l�ɁAWordCheckServer�f�B���N�g�����ɂ�**MasterDBUserData.txt**���쐬���AAnpanMMOMaster�f�[�^�x�[�X���Q�Ƃ��郆�[�U������s�ڂɁA�p�X���[�h���s�ڂɋL�q����B

# �T�[�o�N���ɂ��Ē��ӓ_
�Q�[���T�[�o�iAnpanMMOServer�j�́A�N�����ɃL���b�V���T�[�o�ƃ��[�h�`�F�b�N�T�[�o�ɐڑ����邽�߁A�N�����ɃL���b�V���T�[�o�ƃ��[�h�`�F�b�N�T�[�o���N�����Ă��Ȃ��ƋN���ł��܂���B  
��Linux�̏ꍇ��Server�f�B���N�g���ɂ���AllBuild.sh�����s���邾���Ŏ����I�ɃL���b�V���T�[�o�����[�h�`�F�b�N�T�[�o���Q�[���T�[�o�̏��ɋN�����܂��B�i���{���̓r���h���s�����߂̃X�N���v�g�ł��B�j�@
