ShowMessage("選択肢テスト")
PushSelection("選択肢１")
PushSelection("選択肢２")
PushSelection("選択肢３")
ShowSelection()

if (Selected == 0) then
	ShowMessage("選択肢１です。)
	local bFlag = GetFlag(Test1)
	if (!bFlag) then
		ShowMessage("フラグが立っていないので立てます。")
		SetFlag(Test1)
	else
		ShowMessage("フラグが立っています。")
	end
elseif (Selected == 1) then
	ShowMessage("選択肢２です。)
	local bFlag = GetFlag(Test2)
	if (!bFlag) then
		ShowMessage("フラグが立っていないので立てます。")
		SetFlag(Test2)
	else
		ShowMessage("フラグが立っています。")
	end
else
	ShowMessage("選択肢３です。)
	local bFlag = GetFlag(Test3)
	if (!bFlag) then
		ShowMessage("フラグが立っていないので立てます。")
		SetFlag(Test3)
	else
		ShowMessage("フラグが立っています。")
	end
end