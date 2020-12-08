.586      
.model flat      
.code   

_media_vettore proc 	
push ebp
mov ebp, esp

sub esp, 8
push esi
push edi
push ebx

mov ebx, dword ptr[ebp + 8]		;indirizzo del vettore
mov ecx, dword ptr[ebp +12]		;lunghezza del vettore
mov esi, 0						;scorro il vettore
mov edi, 0						;variabile di accumulo della somma

call _somma

call _divisione

pop ebx
pop edi
pop esi
mov esp, ebp
pop ebp
ret

_media_vettore endp

_somma proc

ciclo:
	cmp ecx, esi
	je fine_1
	add edi, [ebx + 4*esi]
	inc esi
	jmp ciclo
	   
fine_1:
	ret

_somma endp

_divisione proc

mov edx, 0
mov eax, edi
div ecx

ret


_divisione endp

End	
