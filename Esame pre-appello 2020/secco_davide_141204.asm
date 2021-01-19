.586
.model flat
.code

_elimina_doppie proc

push ebp
mov ebp, esp
sub esp, 8

push esi
push edi
push ebx

call inizio

call ciclo1


mov eax, edi

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp
ret

_elimina_doppie endp

inizio proc

mov eax, 0

mov ebx,dword ptr[ebp+8]		;salvo la stringa
mov ah, byte ptr[ebp+12]		;salvo il carattere che devo trovare
mov edi, 0						;conta le coppie trovate
ret

inizio endp

ciclo1 proc

mov esi, 0						;mi fa scorrere il vettore

ciclo_1:
	mov al, byte ptr[ebx+esi]
	cmp al, 0
	je fine1
	
	cmp al, ah
	je trovato

return1:
	inc esi
	jmp ciclo_1

trovato: 
	call trovato_carattere
	jmp ciclo_1						;!!!!occhio qui!!!

fine1:
	ret
ciclo1 endp

trovato_carattere proc

inc esi							;vado al carattere successivo

mov cl, byte ptr[ebx+esi]		;salvo il carattere successivo
cmp cl, 0
je fine_2
cmp al, cl						;se i due caratteri sono diversi, torno al ciclo
jne fine_2

;i due caratteri sono uguali:

inc esi							;vado a 2 caratteri dopo
mov cl, byte ptr[ebx+esi]
cmp cl, 0
je trovata_coppia
cmp cl, ah
jne	trovata_coppia				;se questo carattere non è uguale agli altri, ho trovato una coppia!

;se invece ce ne sono 3 in fila devo scorrere finchè non sono finiti
call ciclo_scorre


fine_2:
	inc esi
	ret

trovata_coppia:
	inc edi
	dec esi
	mov byte ptr[ebx+esi]," "
	dec esi
	mov byte ptr[ebx+esi]," "
	add esi,2
	ret

trovato_carattere endp

ciclo_scorre proc

ciclo3:
	mov cl, byte ptr[ebx+esi]
	cmp cl, 0
	je fine_ciclo_scorrimento
	cmp cl, ah
	jne fine_ciclo_scorrimento
	inc esi
	jmp ciclo3

fine_ciclo_scorrimento:
	dec esi
	ret

ciclo_scorre endp

end