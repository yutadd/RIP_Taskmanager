# lock_core_VS_std_thread
Compared that locking CPU core and using std:thread
コア似スレッドを割り当てちゃうのとstd:threadを使ってタスクのコア割当を任せちゃうのどっちが早いか気になったから作ってみたYO
このコードでの条件だといがいと任せちゃうほうが速かった...
Benched for 30sec.
assign thread to core:    267161689
assign free thread:       822861222
assign std:thread to core:363581241
assign free std:thread:   894167643
