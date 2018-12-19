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

-- クエスト進行.
function ProgressQuest(QuestId)
	ProgressQuest_Impl(this, QuestId)
end

-- クエストのステージ番号を取得.
function GetQuestStageNo(QuestId)
	local StageNo = GetQuestStageNo_Impl(this, QuestId)
	return StageNo
end

-- アイテムの個数を取得.
function GetItemCount(ItemId)
	local Count = GetItemCount_Impl(this, ItemId)
	return Count
end

-- アイテムを消費.
function ConsumeItem(ItemId, Count)
	ConsumeItem_Impl(this, ItemId, Count)
end
