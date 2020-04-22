program P11053
    implicit none

    integer, dimension(1000) :: sequence
    integer, dimension(1000) :: max_length_up_to
    integer :: length
    integer :: i, j
    integer :: result

    read (*, *) length
    read (*, *) (sequence(i), i = 1, length)

    max_length_up_to(1) = 1
    do i = 2, length
        max_length_up_to(i) = 1
        do j = 1, i - 1
            if (sequence(i) > sequence(j)) then
                max_length_up_to(i) = max(max_length_up_to(j) + 1, max_length_up_to(i))
            end if
        end do
    end do

    result = 0
    do i = 1, length
        result = max(max_length_up_to(i), result)
    end do
    write (*, '(I0)') result
end program P11053