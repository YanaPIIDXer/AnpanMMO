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
