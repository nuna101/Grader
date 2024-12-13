void shift(int k) {
	// TODO: Add your code here
	if(k > 0) {
		for(int i = 0; i < k%mSize; ++i) {
			mHeader->prev->next = mHeader->next;
			mHeader->next->prev = mHeader->prev;
			mHeader->prev = mHeader->next;
			mHeader->next = mHeader->next->next;
			mHeader->prev->next = mHeader;
			mHeader->next->prev = mHeader;
		}
	} 
	else if(k < 0) {
		k = -1*k;
		for(int i = 0; i < k%mSize; ++i) {
			mHeader->prev->next = mHeader->next;
			mHeader->next->prev = mHeader->prev;
			mHeader->next = mHeader->prev;
			mHeader->prev = mHeader->next->prev;
			mHeader->prev->next = mHeader;
			mHeader->next->prev = mHeader;
		}
	}
}
