program P18868
    implicit none
    integer :: n_space, n_planet, i, j, k, l, count
    integer, dimension(10, 100) :: sizes
    logical :: success
    read *, n_space, n_planet
    do i = 1, n_space
        read *, (sizes(i, j), j = 1, n_planet)
    end do
    count = 0
    do i = 2, n_space
        do j = 1, i - 1
            success = .true.
            do k = 2, n_planet
                do l = 1, k - 1
                    if (sizes(i, l) < sizes(i, k) .and. sizes(j, l) >= sizes(j, k)) then
                        success = .false.
                        exit
                    else if (sizes(i, l) == sizes(i, k) .and. sizes(j, l) /= sizes(j, k)) then
                        success = .false.
                        exit
                    else if (sizes(i, l) > sizes(i, k) .and. sizes(j, l) <= sizes(j, k)) then
                        success = .false.
                        exit
                    end if
                end do
                if (.not. success) then
                    exit
                end if
            end do
            if (success) then
                count = count + 1
            end if
        end do
    end do
    write (*, '(I0)') count
end program P18868