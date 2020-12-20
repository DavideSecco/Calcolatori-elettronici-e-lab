.586
.model flat
.code

_conta_vocali_consonanti proc

push ebp
mov ebp, esp

sub esp, 8

push esi
push edi
push ebx

call inizializzazione

call conta

mov eax, dword ptr[ebp+12]
mov [eax], ecx
mov eax, dword ptr[ebp+16]
mov [eax], edx

call caso_1

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp
ret

_conta_vocali_consonanti endp

inizializzazione proc

mov ebx, dword ptr[ebp+8]		;[ebp+8] c'è la stringa
								;[ebp + 12] contatore per le vocali
								;[ebp + 16] contatore per le consonanti

inizializzazione endp

conta proc
mov edx, 0			;conto consonanti
mov ecx, 0			;conto le vocali
mov edi, 0			;scorro il vettore

ciclo_1:
	mov eax, 0
	mov al, byte ptr[ebx+edi]
	cmp al, 0
	je fine_1

	;controllo che sia una lettera:
	cmp al, 65
	jb return
	cmp al, 122
	ja return

	cmp al, 91
	je return
	cmp al, 92
	je return
	cmp al, 93
	je return
	cmp al, 94
	je return
	cmp al, 95
	je return
	cmp al, 96
	je return	


	;controllo se è vocale:
	cmp al,'A'
	je vocale
	cmp al,'E'
	je vocale
	cmp al,'I'
	je vocale
	cmp al,'O'
	je vocale
	cmp al,'U'
	je vocale

	cmp al,'a'
	je vocale
	cmp al,'e'
	je vocale
	cmp al,'i'
	je vocale
	cmp al,'o'
	je vocale
	cmp al,'u'
	je vocale

	;allora è consonante:
	inc edx
return:
	inc edi
	jmp ciclo_1

vocale:
	inc ecx
	jmp return

fine_1:
	ret

conta endp

caso_1 proc

cmp ecx, 0
jne fine_2
cmp edx, 0
jne fine_2
mov eax, -1
ret

fine_2:
	mov eax, 0
	ret

caso_1 endp

end
