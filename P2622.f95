program P2622
    implicit none
    integer :: length_sum
    integer :: a, b, c
    integer :: count = 0
    read *, length_sum
    do a = 1, length_sum / 3
        do b = a, length_sum
            c = length_sum - a - b
            if (b <= c .and. (a + b) > c) then
                count = count + 1
            end if
        end do
    end do
    write (*, '(I0)') count
end program P2622