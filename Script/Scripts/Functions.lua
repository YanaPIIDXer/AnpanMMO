-- メッセージ表示.
function ShowMessage(Message)
	ShowMessage_Impl(this, Message)
	coroutine.yield(1)
end

-- 選択肢をプッシュ
function PushSelection(Message)
	PushSelection_Impl(this, Message)
end

-- 選択肢を表示.
function ShowSelection()
	ShowSelection_Impl(this)
	coroutine.yield(1)
end

-- フラグをセット。
function SetFlag(FlagName)
	SetFlag_Impl(this, FlagName)
end

-- フラグを取得.
function GetFlag(FlagName)
	local Flag = GetFlag_Impl(this, FlagName)
	return Flag
end

-- クエストが進行中か？
function IsQuestActive(QuestId)
	local bIsActive = IsQuestActive_Impl(this, QuestId)
	return bIsActive
end
