ShowMessage("Test1")
ShowMessage("Test2")
ShowMessage("Test3")
ShowMessage("日本語テスト")

local bFlag = GetFlag(Flag)
if (bFlag) then
	ShowMessage("フラグはtrueです。")
else
	ShowMessage("フラグはfalseです。")
end

SetFlag(Flag)
bFlag = GetFlag(Flag)
if (bFlag) then
	ShowMessage("フラグはtrueです。")
else
	ShowMessage("フラグはfalseです。")
end
