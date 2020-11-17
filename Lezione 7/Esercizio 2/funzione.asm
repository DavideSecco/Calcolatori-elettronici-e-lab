; Devi ancora finirlo!!!!!!

.586
.model flat
.code

_sommavett proc 

push ebp 
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0
mov ecx, dword ptr[ebp+8]
mov edx, dword ptr[ebp+12]
mov eax, 0

ciclo:
cmp esi, dword ptr[ebp+16]
je fine_ciclo

mov ebx, dword ptr [ecx+esi*4]
mov edx, dword ptr [edx+esi*4]

add eax, ebx

inc esi
jmp ciclo

fine_ciclo:


pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

_sommavett endp

; nuova funzione
; nuova convenzione: 
; i parametri della mia funzione solo indirizzo vettore 1 in ecx e indirizzo verttore 2 in edx
; in edi ho la lunghezza del vettore
; in ebx c'e' la somma dei vettori
; i registri ESI, EDI e E ECX devono essere ripristinati

fagiolo proc

push esi
push edi
push ecx

mov ebx, 0
mov esi, 0
ciclo_1: 
cmp esi, edi
je fine_ciclo_1

mov eax, dword ptr [ecx+esi*4]
add eax, dword ptr [edx+esi*4]

inc esi
jmp ciclo_1

fine_ciclo_1


pop ecx
pop edi
pop esi

fagiolo endp

end
