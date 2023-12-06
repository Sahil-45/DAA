def is_safe(board, row, col, n):
    # Check for queens in the same row on the left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check for queens in the upper diagonal on the left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check for queens in the lower diagonal on the left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, n):
    if col >= n:
        return True

    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1

            if solve_nqueens_util(board, col + 1, n):
                return True

            board[i][col] = 0  # Backtrack if placing a queen at board[i][col] doesn't lead to a solution

    return False


def solve_nqueens(n):
    # Initialize the chessboard
    board = [[0 for _ in range(n)] for _ in range(n)]

    if not solve_nqueens_util(board, 0, n):
        print("No solution exists.")
        return

    for row in board:
        print(" ".join(["Q" if cell == 1 else "." for cell in row]))


n = 6
solve_nqueens(n)
