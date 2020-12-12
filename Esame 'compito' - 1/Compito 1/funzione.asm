.586
.model flat
.code

_togli_dispari proc

push ebp
mov ebp, esp

sub esp, 8
push esi
push edi
push ebx

call inizializzazione

call ciclo


pop esi
pop edi
pop ebx

mov esp, ebp
pop ebp
ret

_togli_dispari endp

inizializzazione proc

mov ebx, dword ptr[ebp + 8]		;metto in ebx il valore del vettore		
mov esi, 1						;metto il contatore a 1 (il primo valore del vettore non sarà mai a 0)
mov ecx, 2						;serve per dividere		
								;la lunghezza del vettore è in [ebp+12]

ret

inizializzazione endp

ciclo proc

ciclo_1:
	cmp esi, [ebp+12]
	je fine_1

	mov eax, 0
	mov al, byte ptr[ebx + esi]
	;CHIEDERE come fare in fretta per vedere se un numero è pari o dispari
	Test al, 1
	jnz dispari   ; jump on carry (salta se il carry è 1)
	; qui è pari
	inc esi
	jmp ciclo_1
	
dispari:
	; qui è dispari
	call e_dispari
	inc esi
	jmp ciclo_1

fine_1:
	ret

ciclo endp

e_dispari proc

;controllo che il numero precedente sia pari:
add esi, -1
mov al, byte ptr[ebx + esi]
Test al, 1
jnz fine_2


;controllo che il numero successivo sia pari:
add esi, 2
mov al, byte ptr[ebx + esi]
Test al, 1
jnz fine_2

;sostituisco il valore del numero con la media dei due
call media


fine_2:
	ret

e_dispari endp

media proc
sub esi,2
add al, byte ptr[ebx+esi]
div ecx
inc esi

Test al, 1
jz fine_3
add al, 1					;nel caso il risultato sia dispari +1

fine_3:
mov byte ptr[ebx + esi], al
ret

media endp

end