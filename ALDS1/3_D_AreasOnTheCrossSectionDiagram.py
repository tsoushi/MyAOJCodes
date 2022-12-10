# 水たまりクラス
#     self.leftSideIndex: 水たまりの左端のインデックス
#     self.area: 水たまりの面積
class Puddle:
    def __init__(self, leftSideIndex: int, area: int):
        self.leftSideIndex: int = leftSideIndex
        self.area: int = area

leftSideStack = [] # '\'が出現したインデックスを保持するスタック
puddles = [] # 水たまりのリスト

for i, c in enumerate(input()):
    if c == '\\':
        leftSideStack.append(i)
    if c == '/' and len(leftSideStack) > 0:
        leftSideIndex = leftSideStack.pop() # 直近の'\'のインデックスを取得する
        area = i - leftSideIndex
        
        # 水たまりの統合を行う
        #     現在処理中の水たまりの左端より右側にある水たまりは統合を行う
        while puddles and puddles[-1].leftSideIndex > leftSideIndex:
            area += puddles.pop().area
        
        puddles.append(Puddle(leftSideIndex, area))

# 結果を出力
print(sum([i.area for i in puddles]))
print(len(puddles), end='')
if puddles:
    print(' ' + ' '.join([str(i.area) for i in puddles]), end='')
print()
