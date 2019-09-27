open Alcotest;
open Pastel;

let helloIteamers = () => {
  let expected =
    <Pastel italic=true color=Green>
      "Hello "
      <Pastel underline=true color=Cyan> {"Iteamer" ++ "!"} </Pastel>
    </Pastel>;

  check(string, "hello", Cli.run(~args=[|"def", "Iteamers"|]), expected);
};

let cliTest = ("CLI - Hello", [test_case("runs", `Quick, helloIteamers)]);

let () = {
  run("CLI", [cliTest]);
};
