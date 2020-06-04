program P8370
    implicit none
    integer :: business_rows, business_cols
    integer :: economic_rows, economic_cols
    read *, business_rows, business_cols, economic_rows, economic_cols
    write (*, '(I0)') business_rows * business_cols + economic_rows * economic_cols
end program P8370