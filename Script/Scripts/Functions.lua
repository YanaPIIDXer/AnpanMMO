-- ���b�Z�[�W�\��.
function ShowMessage(Message)
	ShowMessage_Impl(this, Message)
	coroutine.yield(1)
end

-- �I�������v�b�V��
function PushSelection(Message)
	PushSelection_Impl(this, Message)
end

-- �I������\��.
function ShowSelection()
	ShowSelection_Impl(this)
	coroutine.yield(1)
end

-- �t���O���Z�b�g�B
function SetFlag(FlagName)
	SetFlag_Impl(this, FlagName)
end

-- �t���O���擾.
function GetFlag(FlagName)
	local Flag = GetFlag_Impl(this, FlagName)
	return Flag
end
