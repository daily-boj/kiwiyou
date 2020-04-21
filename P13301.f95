program P13301
    implicit none

    integer(8) :: current, prev, temp
    integer :: n
    integer :: i

    read (*,*) n

    current = 4
    prev = 2
    do i = 2, n
        temp = current
        current = current + prev
        prev = temp
    end do
    write (*, '(I0)') current

end program P13301