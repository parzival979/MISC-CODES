; ModuleID = 'program_suite/2-3.bc'
source_filename = "program_suite/2-out-of-bounds-sym.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [4 x i8] c"arr\00", align 1
@.str.1 = private unnamed_addr constant [10 x i8] c"Balanced\0A\00", align 1
@.str.2 = private unnamed_addr constant [12 x i8] c"Unbalanced\0A\00", align 1

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !dbg !9 {
entry:
  %retval = alloca i32, align 4
  %arr = alloca [10 x i8], align 1
  %count = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [10 x i8]* %arr, metadata !13, metadata !DIExpression()), !dbg !18
  %0 = bitcast [10 x i8]* %arr to i8*, !dbg !19
  call void @klee_make_symbolic(i8* %0, i64 10, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0)), !dbg !20
  call void @llvm.dbg.declare(metadata i32* %count, metadata !21, metadata !DIExpression()), !dbg !22
  store i32 0, i32* %count, align 4, !dbg !22
  call void @llvm.dbg.declare(metadata i32* %i, metadata !23, metadata !DIExpression()), !dbg !25
  store i32 0, i32* %i, align 4, !dbg !25
  br label %for.cond, !dbg !26

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, i32* %i, align 4, !dbg !27
  %cmp = icmp slt i32 %1, 100, !dbg !29
  br i1 %cmp, label %for.body, label %for.end, !dbg !30

for.body:                                         ; preds = %for.cond
  %2 = load i32, i32* %i, align 4, !dbg !31
  %idxprom = sext i32 %2 to i64, !dbg !34
  %arrayidx = getelementptr inbounds [10 x i8], [10 x i8]* %arr, i64 0, i64 %idxprom, !dbg !34
  %3 = load i8, i8* %arrayidx, align 1, !dbg !34
  %conv = sext i8 %3 to i32, !dbg !34
  %cmp1 = icmp eq i32 %conv, 97, !dbg !35
  br i1 %cmp1, label %if.then, label %if.else, !dbg !36

if.then:                                          ; preds = %for.body
  %4 = load i32, i32* %count, align 4, !dbg !37
  %inc = add nsw i32 %4, 1, !dbg !37
  store i32 %inc, i32* %count, align 4, !dbg !37
  br label %for.inc, !dbg !38

if.else:                                          ; preds = %for.body
  %5 = load i32, i32* %count, align 4, !dbg !39
  %dec = add nsw i32 %5, -1, !dbg !39
  store i32 %dec, i32* %count, align 4, !dbg !39
  br label %for.inc

for.inc:                                          ; preds = %if.then, %if.else
  %6 = load i32, i32* %i, align 4, !dbg !40
  %inc3 = add nsw i32 %6, 1, !dbg !40
  store i32 %inc3, i32* %i, align 4, !dbg !40
  br label %for.cond, !dbg !41, !llvm.loop !42

for.end:                                          ; preds = %for.cond
  %7 = load i32, i32* %count, align 4, !dbg !45
  %cmp4 = icmp eq i32 %7, 0, !dbg !47
  br i1 %cmp4, label %if.then6, label %if.else7, !dbg !48

if.then6:                                         ; preds = %for.end
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.1, i64 0, i64 0)), !dbg !49
  br label %if.end9, !dbg !49

if.else7:                                         ; preds = %for.end
  %call8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.2, i64 0, i64 0)), !dbg !50
  br label %if.end9

if.end9:                                          ; preds = %if.else7, %if.then6
  ret i32 0, !dbg !51
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare dso_local void @klee_make_symbolic(i8*, i64, i8*) #2

declare dso_local i32 @printf(i8*, ...) #2

attributes #0 = { noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6, !7}
!llvm.ident = !{!8}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "program_suite/2-out-of-bounds-sym.c", directory: "/home/klee/hw2")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{i32 7, !"uwtable", i32 1}
!7 = !{i32 7, !"frame-pointer", i32 2}
!8 = !{!"clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)"}
!9 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 4, type: !10, scopeLine: 4, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!10 = !DISubroutineType(types: !11)
!11 = !{!12}
!12 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!13 = !DILocalVariable(name: "arr", scope: !9, file: !1, line: 5, type: !14)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !15, size: 80, elements: !16)
!15 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!16 = !{!17}
!17 = !DISubrange(count: 10)
!18 = !DILocation(line: 5, column: 10, scope: !9)
!19 = !DILocation(line: 6, column: 24, scope: !9)
!20 = !DILocation(line: 6, column: 5, scope: !9)
!21 = !DILocalVariable(name: "count", scope: !9, file: !1, line: 8, type: !12)
!22 = !DILocation(line: 8, column: 9, scope: !9)
!23 = !DILocalVariable(name: "i", scope: !24, file: !1, line: 9, type: !12)
!24 = distinct !DILexicalBlock(scope: !9, file: !1, line: 9, column: 5)
!25 = !DILocation(line: 9, column: 14, scope: !24)
!26 = !DILocation(line: 9, column: 10, scope: !24)
!27 = !DILocation(line: 9, column: 21, scope: !28)
!28 = distinct !DILexicalBlock(scope: !24, file: !1, line: 9, column: 5)
!29 = !DILocation(line: 9, column: 23, scope: !28)
!30 = !DILocation(line: 9, column: 5, scope: !24)
!31 = !DILocation(line: 10, column: 17, scope: !32)
!32 = distinct !DILexicalBlock(scope: !33, file: !1, line: 10, column: 13)
!33 = distinct !DILexicalBlock(scope: !28, file: !1, line: 9, column: 34)
!34 = !DILocation(line: 10, column: 13, scope: !32)
!35 = !DILocation(line: 10, column: 20, scope: !32)
!36 = !DILocation(line: 10, column: 13, scope: !33)
!37 = !DILocation(line: 11, column: 18, scope: !32)
!38 = !DILocation(line: 11, column: 13, scope: !32)
!39 = !DILocation(line: 13, column: 18, scope: !32)
!40 = !DILocation(line: 9, column: 31, scope: !28)
!41 = !DILocation(line: 9, column: 5, scope: !28)
!42 = distinct !{!42, !30, !43, !44}
!43 = !DILocation(line: 14, column: 5, scope: !24)
!44 = !{!"llvm.loop.mustprogress"}
!45 = !DILocation(line: 16, column: 8, scope: !46)
!46 = distinct !DILexicalBlock(scope: !9, file: !1, line: 16, column: 8)
!47 = !DILocation(line: 16, column: 14, scope: !46)
!48 = !DILocation(line: 16, column: 8, scope: !9)
!49 = !DILocation(line: 17, column: 9, scope: !46)
!50 = !DILocation(line: 19, column: 9, scope: !46)
!51 = !DILocation(line: 21, column: 5, scope: !9)
