-- メッセージ表示.
function ShowMessage(Message)
	ShowMessage_Impl(Message)
	coroutine.yield()
end

-- 選択肢をプッシュ
function PushSelection(Message)
	PushSelection_Impl(Message)
end

-- 選択肢を表示.
function ShowSelection()
	ShowSelection_Impl()
	coroutine.yield()
end
