# lock_core_VS_std_thread<br>
Compared that locking CPU core and using std:thread<br>
コア似スレッドを割り当てちゃうのとstd:threadを使ってタスクのコア割当を任せちゃうのどっちが早いか気になったから作ってみたYO<br>
このコードでの条件だといがいと任せちゃうほうが速かった...<br>
Benched for 30sec.<br>
assign thread to core:    267161689<br>
assign free thread:       822861222<br>
assign std:thread to core:363581241<br>
assign free std:thread:   894167643<br>
