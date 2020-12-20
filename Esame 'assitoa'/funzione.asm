.586
.model flat
.code

_assitoa proc

push ebp
mov ebp, esp
sub esp, 8

push esi
push edi
push ebx

call inizio

call cifre

call scrivo


pop ebx
pop edi
pop ebx

mov esp, ebp
pop ebp
ret
 
_assitoa endp

inizio proc

mov ebx, dword ptr[ebp+16]		;in ebx ho la stringa dove devo scrivere
mov eax, dword ptr[ebp +8]		;in eax c'è il numero

ret
inizio endp

cifre proc

mov edi, 10			;serve per dividere
mov esi, 1			;conto quante cifre ha il numero

ciclo_1:
	mov edx, 0
	div edi
	cmp eax, 10
	jb fine_1
	inc esi
	jmp ciclo_1

fine_1:
	ret

cifre endp

scrivo proc

mov edx, 0
mov edi, 0
mov eax, dword ptr[ebp +8]
push eax							;contatore per la stringa
									;in esi ho la potenza del 10 da usare
ciclo_2:
	cmp edi,esi
	ja fine_2
	call potenza		
	mov ecx, eax					;in ecx ho 100-10-1 

	mov eax, dword ptr[ebp - 28]
	mov edx, 0						;in eax c'è il numero rimanente o di partenza
	div ecx							;divido, in eax ci sarà il risultato, che va messo nella stringa

	add eax, 48
	mov dword ptr[ebp-28], edx		;salvo il resto per il prossimo giro
	mov byte ptr[ebx + edi], al		;scrivo nel vettore
	inc edi							;scorro il ciclo
	jmp ciclo_2

fine_2:
	pop eax
	ret
	

scrivo endp

potenza proc

mov ecx, edi
mov eax, 1


ciclo_3:
	cmp ecx, esi
	je fine_3
	mov edx, 10
	mul edx
	inc ecx
	jmp ciclo_3

fine_3: 
	ret

potenza endp

end