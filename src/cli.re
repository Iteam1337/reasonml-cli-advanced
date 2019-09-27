module Command = {
  /* --greet=Tom */
  let parse = text => {
    let split = Tablecloth.String.split(~on="=", text);

    Console.log(("Split", split));
    split;
    /* switch (split) { */
    /* | ["--greet", name] => `Greet(name) */
    /* | [_, command] => `Unknown(command) */
    /* }; */
  };
};

let run = (~args) => {
  /* A collection of std-library functions */
  let firstRealArg =
    args
    |> Array.get(~index=1)
    |> Option.withDefault(~default="No arguments passed.");

  let _commands = args |> Array.map(~f=Command.parse);

  /* A JSX-like text-formatting library:
     https://reason-native.com/docs/pastel/ */
  Pastel.(
    <Pastel italic=true color=Green>
      "Hello "
      <Pastel underline=true color=Cyan> {firstRealArg ++ "!"} </Pastel>
    </Pastel>
  );
};
