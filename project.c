Status ListInsert( SqList &L, int i, ElemType e )
{
	if(i<1||i>L.length+1){
		return ERROR;
	}
	if(L.length>=L.listsize){
		return ERROR;
	}
	L.elem[L.length]=e;
	L.length++;
	L.listsize++;
	return OK;
}

Status GetElem( SqList L, int i, ElemType &e ){
	if(i<1||i>L.length){
		return ERROR; 
	}
	e=L.elem[i-1];
	return OK;
}

int    ListLength( SqList L){
	return L.length;
}