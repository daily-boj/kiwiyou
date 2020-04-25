program P18187
    implicit none
    integer :: count, lines
    integer, dimension(102) :: sequence
    integer :: i

    read (*, *) lines
    do i = 1, ((lines + 2) / 3)
        sequence(i * 3 - 2) = i * 2 - 1
        sequence(i * 3 - 1) = i * 2
        sequence(i * 3) = i * 2 + 1
    end do

    count = 1
    do i = 1, lines
        count = count + sequence(i)
    end do
    write (*, '(I0)') count

end program P18187