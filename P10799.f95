program P10799
    implicit none
    character(len = 100000) :: parens
    integer :: stack, sum
    integer :: i

    read *, parens
    sum = 0
    stack = 0
    do i = 1, len_trim(parens)
        if (parens(i:i) == '(') then
            stack = stack + 1
        else if (parens(i:i) == ')') then
            stack = stack - 1
            if (parens((i - 1):(i - 1)) == '(') then
                sum = sum + stack
            else
                sum = sum + 1
            end if
        end if
    end do
    write (*, '(I0)') sum
end program P10799