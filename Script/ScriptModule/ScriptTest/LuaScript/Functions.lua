-- ���b�Z�[�W�\��.
function ShowMessage(Message)
	ShowMessage_Impl(Message)
	coroutine.yield()
end

-- �I�������v�b�V��
function PushSelection(Message)
	PushSelection_Impl(Message)
end

-- �I������\��.
function ShowSelection()
	ShowSelection_Impl()
	coroutine.yield()
end

-- �t���O���Z�b�g�B
function SetFlag(FlagName)
	SetFlag_Impl(FlagName)
end

-- �t���O���擾.
function GetFlag(FlagName)
	local Flag = GetFlag_Impl(FlagName)
	return Flag
end
