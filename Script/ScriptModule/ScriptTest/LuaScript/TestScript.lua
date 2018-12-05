ShowMessage("Test1")
ShowMessage("Test2")
ShowMessage("Test3")
PushSelection("Test1")
PushSelection("Test2")
PushSelection("Test3")
ShowSelection()
if (Selected == 0) then
	ShowMessage("あなたが選択したのはTest1です。")
elseif (Selected == 1) then
	ShowMessage("あなたが選択したのはTest2です。")
elseif (Selected == 2) then
	ShowMessage("あなたが選択したのはTest3です。")
else
	ShowMessage("エラー")
end

local Flag = GetFlag("Flag")
if (Flag) then
	ShowMessage("フラグはtrueです。")
else
	ShowMessage("フラグはfalseです。")
end

SetFlag("Flag")
Flag = GetFlag("Flag")
if (Flag) then
	ShowMessage("フラグはtrueです。")
else
	ShowMessage("フラグはfalseです。")
end
