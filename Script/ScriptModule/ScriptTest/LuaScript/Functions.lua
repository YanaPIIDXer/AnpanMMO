function ShowMessage(Message)
	local colo = coroutine.create(
		function()
			ShowMessage_Impl(Message)
			coroutine.yield()
		end
	)
	repeat
		coroutine.resume(colo, 0)
	until coroutine.status(colo) == "dead"
end
