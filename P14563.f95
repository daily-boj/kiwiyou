program P14563
    implicit none
    integer :: T, S, D, i
    integer, dimension(1000) :: N
    read *, T
    read *, (N(i), i = 1, T)
    do i = 1, T
        if (N(i) > 1) then
            S = 1
        else
            S = 0
        end if
        D = 2
        do while (D <= sqrt(real(N(i))))
            if (mod(N(i), D) == 0) then
                S = S + D
                if (N(i) / D /= D) then
                    S = S + N(i) / D
                end if
            end if
            D = D + 1
        end do
        if (S > N(i)) then
            write (*, '(A)') 'Abundant'
        else if (S < N(i)) then
            write (*, '(A)') 'Deficient'
        else
            write (*, '(A)') 'Perfect'
        end if
    end do
end program P14563