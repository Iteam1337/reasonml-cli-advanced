open Alcotest;
open Pastel;

let greetTest = () => {
  let expected =
    <Pastel italic=true color=Green>
      "Hello "
      <Pastel underline=true color=Cyan> {"Iteamers" ++ "!"} </Pastel>
    </Pastel>;

  check(
    string,
    "--greet",
    Cli.run(~args=[|"noop", "--greet=Iteamers"|]) |> List.hd,
    expected,
  );
};

let cliTest = ("CLI", [test_case("runs", `Quick, greetTest)]);

let () = {
  run("CLI", [cliTest]);
};
