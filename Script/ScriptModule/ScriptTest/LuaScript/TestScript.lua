ShowMessage("Test1")
ShowMessage("Test2")
ShowMessage("Test3")
PushSelection("Test1")
PushSelection("Test2")
PushSelection("Test3")
ShowSelection()
if (Selected == 0) then
	ShowMessage("���Ȃ����I�������̂�Test1�ł��B")
elseif (Selected == 1) then
	ShowMessage("���Ȃ����I�������̂�Test2�ł��B")
elseif (Selected == 2) then
	ShowMessage("���Ȃ����I�������̂�Test3�ł��B")
else
	ShowMessage("�G���[")
end
