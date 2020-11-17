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

end
