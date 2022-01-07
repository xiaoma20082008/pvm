//
//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                    O\ = /O
//                ____/'---'\____
//               .  ' \\| |// '  .
//               / \\||| : |||// \
//             / _||||| -:- |||||- \
//               | | \\\ - /// | |
//             | \_| ''\---/'' | |
//              \ .-\__ '-' ___/-. /
//           ___'. .' /--.--\ '. .'___
//        ."" '< '.___\_<|>_/___.' >' "".
//       | | : '- \'.;'\ _ /';.'/ - ' : | |
//         \ \ '-. \_ __\ /__ _/ .-' / /
//  ======'-.____'-.___\_____/___.-'____.-'======
//                    '=---='
//
//  .............................................
//          佛祖保佑             永无BUG
//  佛曰:
//          写字楼里写字间，写字间里程序员；
//          程序人员写程序，又拿程序换酒钱。
//          酒醒只在网上坐，酒醉还来网下眠；
//          酒醉酒醒日复日，网上网下年复年。
//          但愿老死电脑间，不愿鞠躬老板前；
//          奔驰宝马贵者趣，公交自行程序员。
//          别人笑我忒疯癫，我笑自己命太贱；
//          不见满街漂亮妹，哪个归得程序员？
//
//  .............................................
//
//  Created by chunxiao ma on 2021/11/3.
//

#include "code/binaryFileParser.hh"
#include "memory/heap.hh"
#include "runtime/interpreter.hh"
#include "runtime/universe.hh"
#include "utils/bufferedInputStream.hh"
#include <iostream>

int main(int argc, char **argv) {
  if (argc <= 1) {
    return 0;
  }

  pvm::Universe::Genesis();

  pvm::BufferedInputStream stream(argv[1]);
  pvm::BinaryFileParser parser(&stream);

  auto *code = parser.Parse();
  pvm::Universe::_main_code = code;
  std::cout << "source code:" << code << std::endl;
  std::cout << "target code:" << pvm::Universe::_main_code << std::endl;

  pvm::Interpreter::GetInstance()->Run(pvm::Universe::_main_code);
  pvm::Universe::_heap->GC();

  pvm::Universe::Destroy();
  return 0;
}