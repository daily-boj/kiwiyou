program P2491
    implicit none

    integer :: length
    integer, dimension(100000) :: sequence
    integer, dimension(100000) :: increasing_up_to, decreasing_up_to
    integer :: i

    integer :: max_length

    read (*,*) length
    read (*,*) (sequence(i), i = 1, length)

    increasing_up_to(1) = 1
    decreasing_up_to(1) = 1

    do i = 2, length
        if (sequence(i) >= sequence(i - 1)) then
            increasing_up_to(i) = increasing_up_to(i - 1) + 1
        else
            increasing_up_to(i) = 1
        end if
        if (sequence(i) <= sequence(i - 1)) then
            decreasing_up_to(i) = decreasing_up_to(i - 1) + 1
        else
            decreasing_up_to(i) = 1
        end if
    end do

    max_length = 0
    do i = 1, length
        max_length = max(max_length, increasing_up_to(i), decreasing_up_to(i))
    end do

    write (*, '(I0)') max_length
end program P2491