program P2579

    integer :: stairs_count
    integer, dimension(300) :: points

    integer :: current, current_skipped, prev, prev_temp

    read (*,*) stairs_count

    do i = 1, stairs_count
        read (*,*) points(i)
    end do

    prev = 0
    current = points(1)
    current_skipped = points(1)

    do i = 2, stairs_count
        prev_temp = max(current, current_skipped)
        current = points(i) + current_skipped
        current_skipped = points(i) + prev
        prev = prev_temp
    end do
    write (*, '(I0)') max(current, current_skipped)

end program